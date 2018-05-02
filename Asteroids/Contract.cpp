#include "Contract.h"
#include "Game.h"






Contract::Contract()
{
}

void Contract::initialise(int t_gem1, int t_gem2, int t_gem3, int t_gem4, int t_gem5, int t_amount)
{
	m_requiredGems[0] = t_gem1;
	m_requiredGems[1] = t_gem2;
	m_requiredGems[2] = t_gem3;
	m_requiredGems[3] = t_gem4;
	m_requiredGems[4] = t_gem5;
	m_value = t_amount;
}



Contract::~Contract()
{
}

void Contract::complete()
{
	m_completed = true;
	for (int i = 0; i < GEM_SLOTS; i++)
	{
		Game::s_gems[i] -= m_requiredGems[i];			
	}
	Game::s_credits += m_value;		
}

bool Contract::check(int t_gems[])
{
	bool result = true;
	for (int i = 0; i < GEM_SLOTS; i++)
	{
		if (m_requiredGems[i] > t_gems[i])
		{
			result = false;
		}
	}
	return result;
}
