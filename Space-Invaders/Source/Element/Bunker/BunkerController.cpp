#include "../../../Header/Element/Bunker/BunkerController.h"
#include "../../../Header/Element/Bunker/BunkerView.h"
#include "../../../Header/Bullet/BulletController.h"
#include "../../../Header/Entity/EntityConfig.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../../Header/Bullet/BulletConfig.h"
#include "../../Header/Sound/SoundService.h"

namespace Element
{
	namespace Bunker 
	{
		using namespace Bullet;
		using namespace Entity;
		using namespace Global;
		using namespace Sound;

		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete (bunkerView);
		}

		void BunkerController::Initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->Initialize(this); // we will discuss this soon
		}

		void BunkerController::Update()
		{
			bunkerView->Update();
		}

		void BunkerController::Render()
		{
			bunkerView->Render();
		}

		sf::Vector2f BunkerController::GetBunkerPosition() const
		{
			return bunkerData.position;
		}

		const sf::Sprite& BunkerController::GetColliderSprite()
		{
			return bunkerView->GetBunkerSprite();
		}

		void BunkerController::OnCollision(ICollider* otherCollider)
		{
			BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

			if (bulletController && bulletController->GetBulletType() == BulletType::TORPEDO)
			{
				ServiceLocator::GetInstance()->GetElementService()->DestroyBunker(this);

				ServiceLocator::GetInstance()->GetAnimationService()->SpawnAnimationSystem(GetBunkerPosition(),
					Animation::AnimationType::EXPLOSION);
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::EXPLOSION);
			}
		}
	}
}