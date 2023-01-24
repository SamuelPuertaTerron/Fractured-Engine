#include "Sandbox.h"

namespace Sandbox
{
	WindowSettings Sandbox::GetWindowSettings()
	{
		WindowSettings windowSettings;
		windowSettings.title = "Fractured Application";
		windowSettings.width = 1280;
		windowSettings.height = 720;
		windowSettings.vsync = true;
		windowSettings.canResize = true;
		windowSettings.windowSettingsInternal.displayFps = true;
		return windowSettings;
	}

    void Sandbox::OnAppCreate()
    {
        //This is where the user would create GameObjects 
        object.id = Engine::GetInstance()->GetScene()->CreateEntity();
        object.AddComponent<RenderComponent>();
        object.GetComponent<RenderComponent>()->Sprite = Engine::GetInstance()->GetRenderer()->GetTexture(0); //This would load a white square which comes with the engine. 
        object2.id = Engine::GetInstance()->GetScene()->CreateEntity();
        object2.AddComponent<RenderComponent>();
        object2.GetComponent<RenderComponent>()->Sprite = Engine::GetInstance()->GetRenderer()->GetTexture(1);
        object2.GetTransform()->Position = { -5.0f, 3.5f }; //Sets the position to -5.0f on the x axis and 3.5f on the y axis

        Engine::GetInstance()->GetScene()->SpawnEntity(object, {-4.0f, 3.0f});
    }
    void Sandbox::OnAppUpdate(float DeltaTime)
    {
        //The Main Update Logic
        //Moving Objects

        if (InputManager::IsKeyPressed(KeyCode::FK_W))
        {
            object.GetTransform()->Position.y += 5.0f * DeltaTime; //Makes the object move up
        }
        if (InputManager::IsKeyPressed(KeyCode::FK_S))
        {
            object.GetTransform()->Position.y -= 5.0f * DeltaTime; //Makes the object move down
        }
        if (InputManager::IsKeyPressed(KeyCode::FK_A))
        {
            object.GetTransform()->Position.x -= 5.0f * DeltaTime; //Makes the object move left
        }
        if (InputManager::IsKeyPressed(KeyCode::FK_D))
        {
            object.GetTransform()->Position.x += 5.0f * DeltaTime; //Makes the object move right
        }

        if (Collision::HasCollided(object, object2))
        {
            //Sets a random positon when you collided with the object2
            object2.GetTransform()->Position.x = Random::RandomNumberInRange(-4.0f, 4.0f);
            object2.GetTransform()->Position.y = Random::RandomNumberInRange(-4.0f, 4.0f);
        }
    }
    void Sandbox::OnAppRender()
    {
        //Where Text will be draw
    }
    void Sandbox::OnAppRenderUI()
	{
        if(GUI::FGUIPanel::StartPanel(GUI::NoDecoration))
        {
            if(GUI::FGUIButton::Button("Press Me!"))
            {
                FR_LOG("Pressed!");
            }
            GUI::FGUIPanel::EndPanel();
        }
	}
    void Sandbox::OnAppQuit()
    {
        //Anything the user wants to do before the game quits
        //Runs before any of the engine quitting code
        //Logs (Only Displayed in Debug Configuration) that the Application is quitting and appends the window title to the end
        FR_LOG_INFO("Quitting Application: ", GetWindowSettings().title);
    }
}


