#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/AnimationSystem/AnimationService.h"

namespace Animation
{
	using namespace Global;
	using namespace UI::UIElement;

	AnimationSystem::AnimationSystem(const AnimationSystemConfig& config)
	{
		animationSystemConfig = config;
		CreateUIElements();
	}

	AnimationSystem::~AnimationSystem()
	{
		delete(animationImage);
	}

	void AnimationSystem::Initialize(sf::Vector2f position)
	{
		animationPosition = position;
		currentFrame = 0;
		frameTime = sf::seconds(animationSystemConfig.frameDuration);

		InitializeImage();
	}

	void AnimationSystem::CreateUIElements()
	{
		animationImage = new ImageView();
	}

	void AnimationSystem::InitializeImage()
	{
		animationImage->Initialize(animationSystemConfig.animationTexturePath, 0, 0, animationPosition);
		animationImage->SetTextureRect(sf::IntRect(0, 0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));

		animationImage->SetScale(animationSystemConfig.spriteSheetWidth, animationSystemConfig.spriteSheetHeight, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight);
	}

	void AnimationSystem::Update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			if (currentFrame + 1 >= animationSystemConfig.numberOFAnimationFrames)
				Destroy();

			currentFrame = (currentFrame + 1) % animationSystemConfig.numberOFAnimationFrames;
			clock.restart();

			animationImage->SetTextureRect(sf::IntRect(
				currentFrame * animationSystemConfig.tileWidth,
				0,
				animationSystemConfig.tileWidth,
				animationSystemConfig.tileHeight));
		}
		animationImage->Update();
	}

	void AnimationSystem::Render()
	{
		animationImage->Render();
	}

	void AnimationSystem::Destroy()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->DestroyAnimationSystem(this);
	}
}