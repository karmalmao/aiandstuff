#pragma once

class GameObject;

class Application
{
public:
	Application(int windowWidth, int windowHeight, const char* title);
	~Application();


	void Run();

	void Load();
	void Unload();
	void Update(float deltaTime);
	void Draw();
protected:
private:
	int m_windowWidth;
	int m_windowHeight;
	const char* m_windowTitle;

	GameObject* m_player1 = nullptr;
	GameObject* m_player2 = nullptr;

};
