#include "KeyboardBehaviour.h"
#include "GameObject.h"
#include "raylib.h"
#include <sstream>


KeyboardBehaviour::KeyboardBehaviour() : 
Behaviour()
{
    m_upKey = KEY_W;
    m_downKey = KEY_S;
    m_leftKey = KEY_A;
    m_rightKey = KEY_D;
}
KeyboardBehaviour::KeyboardBehaviour(int upKey, int downKey, int leftKey, int rightKey,float moveForce) :
Behaviour(),
m_upKey(upKey),
m_downKey(downKey),
m_leftKey(leftKey),
m_rightKey(rightKey),
m_moveForce(moveForce)
{

}

KeyboardBehaviour::~KeyboardBehaviour()
{

}
void KeyboardBehaviour::Update(GameObject* obj, float deltaTime) 
{
    if (IsKeyDown(m_upKey)) obj->ApplyForce({ 0,-m_moveForce });
    if (IsKeyDown(m_downKey)) obj->ApplyForce({ 0,m_moveForce });
    if (IsKeyDown(m_leftKey)) obj->ApplyForce({ -m_moveForce,0 });
    if (IsKeyDown(m_rightKey)) obj->ApplyForce({ m_moveForce,0 });
}
 void KeyboardBehaviour::Draw(GameObject* obj)
{
     Vector2 vel = obj->GetVelocity();
     Vector2 pos = obj->GetPosition();
     std::stringstream ss;
     std::string s;
     ss << vel.x + vel.y;
     ss >> s;
     DrawText(s.c_str(), pos.x, pos.y + 20.0f, 10, BLACK);
}