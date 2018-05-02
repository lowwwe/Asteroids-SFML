#pragma once
const int GEM_SLOTS = 5;

class Contract
{
public:
	Contract();
	void initialise(int t_gem1, int t_gem2, int t_gem3, int t_gem4, int t_gem5, int t_amount);
	~Contract();
	bool m_completed = false;
	bool m_possible = false;
	int m_requiredGems[GEM_SLOTS];
	int m_value;

	void complete();
	bool check(int t_gems[]);
	
};

