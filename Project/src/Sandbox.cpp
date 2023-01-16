#include "Sandbox.h"

#include "Fractured/Actor/FActor.h"
#include "Fractured/Input/FInputManager.h"
#include "Fractured/Physiscs/FCollisions.h"
#include "Fractured/Rendering/RenderManager.h"

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
		object.id = Engine::GetInstance()->GetScene()->CreateEntity();
		object.GetTransform()->Position = { 5.0f, 0.0f };
		object.AddComponent<RenderComponent>();
		object.GetComponent<RenderComponent>()->Sprite = Engine::GetInstance()->GetRenderer()->GetTexture(0);

		object2.id = Engine::GetInstance()->GetScene()->CreateEntity();
		object2.GetTransform()->Position = { -5.0f, 0.0f };
		object2.AddComponent<RenderComponent>();
		object2.GetComponent<RenderComponent>()->Sprite = Engine::GetInstance()->GetRenderer()->GetTexture(1);
	}
	void Sandbox::OnAppUpdate(float DeltaTime)
	{
		if(InputManager::IsMouseButtonPressed(MouseCode::FM_LEFTMOUSEBUTTON))
		{
		}

		if (InputManager::IsMouseButtonPressed(MouseCode::FM_RIGHTMOUSEBUTTON))
		{
			Engine::GetInstance()->GetScene()->DestroyEntity(object2); 
			FR_LOG_INFO("Deleted Object");
		}

		if(InputManager::IsKeyPressed(KeyCode::FK_W))
		{
			object.GetTransform()->Position.x -= 5.0f * DeltaTime;
		}
		if (InputManager::IsKeyPressed(KeyCode::FK_S))
		{
			object.GetTransform()->Position.x += 5.0f * DeltaTime;
		}

		if(Collision::HasCollided(object, object2))
		{
			
		}
	}
	void Sandbox::OnAppRender()
	{

	}
	void Sandbox::OnAppQuit()
	{
		FR_LOG_INFO("Quitting Application: ", GetWindowSettings().title);
	}
}


