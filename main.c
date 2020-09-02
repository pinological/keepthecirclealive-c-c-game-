
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    float ra = 20.0;
    Color ballColor = RED;
    InitWindow(screenWidth, screenHeight, "Keep circle alive");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        
        //----------------------------------------------------------------------------------
        int ballcon = 1;
        if(ballcon == 1){
        if(IsKeyDown(KEY_SPACE)){
            ra +=5.0f;
        }
           
           ra--;
        
        
        
        if(ra <= 150 && ra >= 90){
            ballColor = GREEN;
        }
        if(ra <90){
            ballColor = BLUE;
        }
        if(ra >150){
            ballColor = RED;
        }
        
        //----------------------------------------------------------------------------------
        
        // Draw
        if(ra >0 && ra< 250 ){
            ballcon = 1;
        }
        else if(ra <0 ){
            ballcon = 0;
        }
        else if(ra >= 250){
            ballcon = 3;
        }
        }
        //----------------------------------------------------------------------------------
        BeginDrawing();
            
            ClearBackground(RAYWHITE);

            if(ballcon == 1){
            DrawText("If Ball touch Border or it srink you will die",60,420,20,ballColor);  
            DrawText(TextFormat("Ball Radius : %0.2f",ra),5,10,20,BLACK);
            
            
            DrawCircleV(ballPosition, ra, ballColor);
            }
            else if(ballcon == 3){
               DrawText("Ball To Big Chill",screenHeight/2,screenWidth/2,20,ballColor); 
               
            }
            else{
               DrawText("You Died lol press R to restart",screenHeight/2,screenWidth/2,20,ballColor); 
               if(IsKeyDown(KEY_R)){
                   ra= 50;
                   ballcon = 1;
               }
            }
            
        EndDrawing();
    
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}