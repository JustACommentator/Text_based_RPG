#include "Combat.h"
#include "Utility.h"
#include "Player.h"
#include "Enemy.h"
#include <queue>
#include "Ally.h"

using namespace std;

Combat::Combat(list<Entity*> _participants)
{
    enemiesAlive = 0;

    participants = _participants;
    // Sort combat participants by initiative (highest acts first)
    participants.sort([](Entity*& a, Entity*& b)
        -> bool {
            return a->initiativeWeight() > b->initiativeWeight();
        });

    queue<Entity*> entityQueue;
    Entity* playerTurn = nullptr;

    for (Entity* e : participants)
    {
        if (Player* p = dynamic_cast<Player*>(e))
        {
            playerTurn = e;
            allies.push_back(e);
            p->setCurrentState(IN_COMBAT);
        }
        else if (Ally* a = dynamic_cast<Ally*>(e))
        {
            allies.push_back(e);
        }
        else if (Enemy* en = dynamic_cast<Enemy*>(e))
        {
            enemiesAlive++;
            enemies.push_back(e);
        }

        util::slow << e->getName() << " joined the battle!\n";
        participants.push_back(e);
    }

    Entity* currentTurn;

    while (enemiesAlive > 0)
    {
        currentTurn = entityQueue.front();
        entityQueue.pop();

        if (currentTurn == playerTurn) // player turn
        {
            dynamic_cast<Player*>(currentTurn)->turn(allies, enemies);
        }
        else if (Ally* a = dynamic_cast<Ally*>(currentTurn)) // ally turn
        {
            
        }
        else // enemy turn
        {
           
        }

        if (currentTurn->getHealth() > 0) // if still alive, move to end of queue
            entityQueue.push(currentTurn);
    }
    dynamic_cast<Player*>(playerTurn)->setCurrentState(IN_OVERWORLD);
}