#include "Application.h"
#include "raylib.h"
#include "GameObject.h"
#include "KeyboardBehaviour.h"
#include "Player.h"
Application::Application(int windowWidth, int windowHeight, const char* windowTitle) : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowTitle(windowTitle)
{

}
Application::~Application()
{

}
void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
	SetTargetFPS(60);
    Load();
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        Update(deltaTime);
        Draw();
    } 

	CloseWindow();
}
void Application::Load() 
{
    m_player1 = new Player();
    m_player1->SetPosition({ m_windowWidth * 0.75f, m_windowHeight * 0.75f });
    m_player1->SetFriction(1.0f);
    m_player1->SetBehaviour(new KeyboardBehaviour(KEY_W,KEY_S,KEY_A,KEY_D, 100));
    
}
void Application::Unload()
{
    delete m_player1;
    m_player1 = nullptr;

    
}
void Application::Update(float deltaTime)
{
    m_player1->Update(deltaTime);
    

}
void Application::Draw()
{
    BeginDrawing();
    ClearBackground(GREEN);

    m_player1->Draw();
   

    EndDrawing();
}