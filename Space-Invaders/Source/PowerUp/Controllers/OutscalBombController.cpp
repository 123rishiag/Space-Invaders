#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type) {}

        OutscalBombController::~OutscalBombController() {}

        void OutscalBombController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetEnemyService()->Reset();
        }
    }
}
