// joystick_test.c
// Ein eigenständiges Testprogramm für die SDL3 Joystick-Funktionalität
// Funktioniert auch ohne verbundenen Joystick

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PLAYER_SIZE 40

// Struktur für Spielerposition
typedef struct {
    float x, y;
} Position;

// Struktur für simulierten Joystick
typedef struct {
    bool active;
    Sint16 x_axis;
    Sint16 y_axis;
    bool buttons[4];
} VirtualJoystick;

// Funktionsprototypen
void draw_player(SDL_Renderer* renderer, Position position);
void print_joystick_info(SDL_Joystick* joystick);
void update_virtual_joystick(VirtualJoystick* vj);
void render_joystick_state(SDL_Renderer* renderer, SDL_Joystick* joystick, VirtualJoystick* vj);

int main(int argc, char* argv[]) {
    // SDL initialisieren
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        SDL_Log("Fehler bei der SDL-Initialisierung: %s", SDL_GetError());
        return 1;
    }
    
    // Joystick-Events aktivieren
    SDL_SetJoystickEventState(SDL_ENABLE);
    
    // Fenster erstellen
    SDL_Window* window = SDL_CreateWindow("SDL3 Joystick Test", WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
    if (!window) {
        SDL_Log("Fehler beim Erstellen des Fensters: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    // Renderer erstellen
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_Log("Fehler beim Erstellen des Renderers: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    // Variablen für Joystick und Player Position
    SDL_Joystick* joystick = NULL;
    SDL_JoystickID joystick_id = -1;
    Position player_pos = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}; // Spieler startet in der Mitte
    VirtualJoystick virtual_joystick = {false, 0, 0, {false}};
    bool running = true;
    Uint64 last_time = SDL_GetTicks();
    
    // Prüfe auf vorhandene Joysticks
    int num_joysticks = SDL_NumJoysticks();
    printf("Verfügbare Joysticks: %d\n", num_joysticks);
    
    if (num_joysticks > 0) {
        joystick = SDL_OpenJoystick(0);
        if (joystick) {
            joystick_id = SDL_GetJoystickInstanceID(joystick);
            print_joystick_info(joystick);
        } else {
            printf("Fehler beim Öffnen des Joysticks: %s\n", SDL_GetError());
        }
    } else {
        printf("Kein Joystick gefunden - verwende virtuellen Joystick mit T,F,G,H Tasten\n");
        printf("T: Virtuellen Joystick aktivieren/deaktivieren\n");
        printf("F,G,H: Joystick-Buttons simulieren\n");
        printf("Pfeiltasten: Joystick-Achsen simulieren\n");
        virtual_joystick.active = true;
    }
    
    // Haupt-Loop
    while (running) {
        // Zeitmessung für konstante Bewegungsgeschwindigkeit
        Uint64 current_time = SDL_GetTicks();
        float delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;
        
        // Event-Verarbeitung
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            
            // Joystick-spezifische Events
            if (event.type == SDL_EVENT_JOYSTICK_ADDED) {
                printf("Joystick angeschlossen!\n");
                if (!joystick) {
                    joystick = SDL_OpenJoystick(0);
                    if (joystick) {
                        joystick_id = SDL_GetJoystickInstanceID(joystick);
                        print_joystick_info(joystick);
                        virtual_joystick.active = false;
                    }
                }
            }
            else if (event.type == SDL_EVENT_JOYSTICK_REMOVED) {
                if (joystick && event.jdevice.which == joystick_id) {
                    printf("Joystick getrennt!\n");
                    SDL_CloseJoystick(joystick);
                    joystick = NULL;
                    joystick_id = -1;
                }
            }
            else if (event.type == SDL_EVENT_JOYSTICK_BUTTON_DOWN) {
                printf("Joystick Button gedrückt: %d\n", event.jbutton.button);
            }
            else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.keysym.sym == SDLK_t) {
                    // Virtuellen Joystick aktivieren/deaktivieren
                    if (!joystick) {
                        virtual_joystick.active = !virtual_joystick.active;
                        printf("Virtueller Joystick %s\n", virtual_joystick.active ? "aktiviert" : "deaktiviert");
                    }
                }
                else if (event.key.keysym.sym == SDLK_f) {
                    virtual_joystick.buttons[0] = true;
                    printf("Virtueller Joystick Button 0 gedrückt\n");
                }
                else if (event.key.keysym.sym == SDLK_g) {
                    virtual_joystick.buttons[1] = true;
                    printf("Virtueller Joystick Button 1 gedrückt\n");
                }
                else if (event.key.keysym.sym == SDLK_h) {
                    virtual_joystick.buttons[2] = true;
                    printf("Virtueller Joystick Button 2 gedrückt\n");
                }
            }
            else if (event.type == SDL_EVENT_KEY_UP) {
                if (event.key.keysym.sym == SDLK_f) {
                    virtual_joystick.buttons[0] = false;
                }
                else if (event.key.keysym.sym == SDLK_g) {
                    virtual_joystick.buttons[1] = false;
                }
                else if (event.key.keysym.sym == SDLK_h) {
                    virtual_joystick.buttons[2] = false;
                }
            }
        }
        
        // Tastatur-Steuerung
        const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
        float move_speed = 200.0f;
        
        if (keyboard_state[SDL_SCANCODE_ESCAPE]) {
            running = false;
        }
        
        // Virtuellen Joystick aktualisieren
        if (virtual_joystick.active) {
            update_virtual_joystick(&virtual_joystick);
        }
        
        // Spieler mit Tastatur bewegen
        if (keyboard_state[SDL_SCANCODE_UP] || keyboard_state[SDL_SCANCODE_W]) {
            player_pos.y -= move_speed * delta_time;
        }
        if (keyboard_state[SDL_SCANCODE_DOWN] || keyboard_state[SDL_SCANCODE_S]) {
            player_pos.y += move_speed * delta_time;
        }
        if (keyboard_state[SDL_SCANCODE_LEFT] || keyboard_state[SDL_SCANCODE_A]) {
            player_pos.x -= move_speed * delta_time;
        }
        if (keyboard_state[SDL_SCANCODE_RIGHT] || keyboard_state[SDL_SCANCODE_D]) {
            player_pos.x += move_speed * delta_time;
        }
        
        // Spieler mit echtem Joystick bewegen
        if (joystick) {
            Sint16 x_axis = SDL_GetJoystickAxis(joystick, 0);
            Sint16 y_axis = SDL_GetJoystickAxis(joystick, 1);
            
            int deadzone = 8000;
            if (abs(x_axis) > deadzone) {
                float normalized_x = (float)x_axis / 32767.0f;
                player_pos.x += normalized_x * move_speed * delta_time;
            }
            if (abs(y_axis) > deadzone) {
                float normalized_y = (float)y_axis / 32767.0f;
                player_pos.y += normalized_y * move_speed * delta_time;
            }
        }
        // Spieler mit virtuellem Joystick bewegen
        else if (virtual_joystick.active) {
            int deadzone = 8000;
            if (abs(virtual_joystick.x_axis) > deadzone) {
                float normalized_x = (float)virtual_joystick.x_axis / 32767.0f;
                player_pos.x += normalized_x * move_speed * delta_time;
            }
            if (abs(virtual_joystick.y_axis) > deadzone) {
                float normalized_y = (float)virtual_joystick.y_axis / 32767.0f;
                player_pos.y += normalized_y * move_speed * delta_time;
            }
        }
        
        // Spieler in Grenzen halten
        if (player_pos.x < 0) player_pos.x = 0;
        if (player_pos.x > WINDOW_WIDTH - PLAYER_SIZE) player_pos.x = WINDOW_WIDTH - PLAYER_SIZE;
        if (player_pos.y < 0) player_pos.y = 0;
        if (player_pos.y > WINDOW_HEIGHT - PLAYER_SIZE) player_pos.y = WINDOW_HEIGHT - PLAYER_SIZE;
        
        // Zeichnen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // Spieler zeichnen
        draw_player(renderer, player_pos);
        
        // Joystick-Status zeichnen
        render_joystick_state(renderer, joystick, &virtual_joystick);
        
        SDL_RenderPresent(renderer);
        
        // Kurze Pause um CPU-Auslastung zu reduzieren
        SDL_Delay(16);
    }
    
    // Aufräumen
    if (joystick) {
        SDL_CloseJoystick(joystick);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

// Zeichnet den Spieler auf dem Bildschirm
void draw_player(SDL_Renderer* renderer, Position position) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_FRect player_rect = {position.x, position.y, PLAYER_SIZE, PLAYER_SIZE};
    SDL_RenderFillRect(renderer, &player_rect);
}

// Gibt Informationen über einen Joystick aus
void print_joystick_info(SDL_Joystick* joystick) {
    if (!joystick) return;
    
    printf("Joystick geöffnet: %s\n", SDL_GetJoystickName(joystick));
    printf("Joystick ID: %d\n", SDL_GetJoystickInstanceID(joystick));
    printf("Anzahl Achsen: %d\n", SDL_GetJoystickNumAxes(joystick));
    printf("Anzahl Buttons: %d\n", SDL_GetJoystickNumButtons(joystick));
    printf("Anzahl Hats: %d\n", SDL_GetJoystickNumHats(joystick));
}

// Aktualisiert den virtuellen Joystick basierend auf Tastaturzustand
void update_virtual_joystick(VirtualJoystick* vj) {
    if (!vj || !vj->active) return;
    
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
    
    // Achsen zurücksetzen
    vj->x_axis = 0;
    vj->y_axis = 0;
    
    // Achsen basierend auf Pfeiltasten einstellen
    if (keyboard_state[SDL_SCANCODE_LEFT]) vj->x_axis = -32767;
    if (keyboard_state[SDL_SCANCODE_RIGHT]) vj->x_axis = 32767;
    if (keyboard_state[SDL_SCANCODE_UP]) vj->y_axis = -32767;
    if (keyboard_state[SDL_SCANCODE_DOWN]) vj->y_axis = 32767;
}

// Zeichnet den Status des Joysticks auf dem Bildschirm
void render_joystick_state(SDL_Renderer* renderer, SDL_Joystick* joystick, VirtualJoystick* vj) {
    // Joystick-Anzeige Position
    int status_x = 50;
    int status_y = 50;
    int status_width = 200;
    int status_height = 200;
    
    // Hintergrund für Joystick-Status
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_FRect status_rect = {status_x, status_y, status_width, status_height};
    SDL_RenderFillRect(renderer, &status_rect);
    
    // Joystick-Achsen Anzeige
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_FRect axis_rect = {status_x + status_width / 2 - 5, status_y + status_height / 2 - 5, 10, 10};
    SDL_RenderFillRect(renderer, &axis_rect);
    
    // Joystick-Achsposition
    if (joystick) {
        float normalized_x = (float)SDL_GetJoystickAxis(joystick, 0) / 32767.0f;
        float normalized_y = (float)SDL_GetJoystickAxis(joystick, 1) / 32767.0f;
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect joy_pos = {
            status_x + status_width / 2 + normalized_x * (status_width / 2) - 5,
            status_y + status_height / 2 + normalized_y * (status_height / 2) - 5,
            10, 10
        };
        SDL_RenderFillRect(renderer, &joy_pos);
        
        // Button-Status
        for (int i = 0; i < SDL_GetJoystickNumButtons(joystick) && i < 4; i++) {
            if (SDL_GetJoystickButton(joystick, i)) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            }
            SDL_FRect button_rect = {status_x + 20 + i * 40, status_y + status_height + 20, 30, 30};
            SDL_RenderFillRect(renderer, &button_rect);
        }
    }
    // Virtuellen Joystick-Status anzeigen
    else if (vj && vj->active) {
        float normalized_x = (float)vj->x_axis / 32767.0f;
        float normalized_y = (float)vj->y_axis / 32767.0f;
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_FRect joy_pos = {
            status_x + status_width / 2 + normalized_x * (status_width / 2) - 5,
            status_y + status_height / 2 + normalized_y * (status_height / 2) - 5,
            10, 10
        };
        SDL_RenderFillRect(renderer, &joy_pos);
        
        // Button-Status
        for (int i = 0; i < 4; i++) {
            if (vj->buttons[i]) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            }
            SDL_FRect button_rect = {status_x + 20 + i * 40, status_y + status_height + 20, 30, 30};
            SDL_RenderFillRect(renderer, &button_rect);
        }
    }
    
    // Status-Text
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_FRect text_bg = {status_x, status_y - 30, status_width, 25};
    SDL_RenderFillRect(renderer, &text_bg);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_FRect text_rect = {status_x + 2, status_y - 28, status_width - 4, 21};
    SDL_RenderFillRect(renderer, &text_rect);
}
