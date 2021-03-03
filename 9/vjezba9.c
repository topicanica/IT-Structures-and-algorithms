#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int wolf;
	int sheep;
	int cabbage;
	int boat;
} State;

State new_game() {
	State s;
	s.wolf = 0;
	s.sheep = 0;
	s.cabbage = 0;
	s.boat = 0;
	return s;
}

void print_state(State *s) {
	printf("boat: %d\ncabbage: %d\nsheep: %d\nwolf: %d\n\n\n", s->boat, s->cabbage, s->sheep, s->wolf);
}

int legal(State *s)
{
	// vuk i ovca sami || ovca i kupus sami
	if ((s->wolf == s->sheep && s->boat != s->sheep) || (s->sheep == s->cabbage && s->boat != s->sheep))
		return 0;
	return 1;
}

int goal_state(State *s)
{
	if (s->sheep == 1 && s->cabbage == 1 && s->wolf == 1 && s->boat == 1)
		return 1;
	return 0;
}

int next_states(State *s, State* nstates)
{
	int ns = 0; // broj novih stanja

	// prenesi kupus
	if (s->boat == s->cabbage)
	{
		nstates[ns].boat = !s->boat;
		nstates[ns].cabbage = !s->cabbage;
		nstates[ns].sheep = s->sheep;
		nstates[ns].wolf = s->wolf;
		ns++;
	}
	// prenesi ovcu
	if (s->boat == s->sheep)
	{
		nstates[ns].boat = !s->boat;
		nstates[ns].cabbage = s->cabbage;
		nstates[ns].sheep = !s->sheep;
		nstates[ns].wolf = s->wolf;
		ns++;
	}
	// prenesi vuka
	if (s->boat == s->wolf)
	{
		nstates[ns].boat = !s->boat;
		nstates[ns].cabbage = s->cabbage;
		nstates[ns].sheep = s->sheep;
		nstates[ns].wolf = !s->wolf;
		ns++;
	}
	// sam brod moze uvijek ici
	nstates[ns].boat = !s->boat;
	nstates[ns].cabbage = s->cabbage;
	nstates[ns].sheep = s->sheep;
	nstates[ns].wolf = s->wolf;
	ns++;

	return ns;
}

int solve(State s, int depth)
{
	if (depth == 0)
		return 0;
	if (goal_state(&s))
	{
		print_state(&s);
		return 1;
	}
	if (!legal(&s))
		return 0;

	State nstates[4];
	int ns = next_states(&s, nstates);

	for (int i = 0; i < ns; i++)
	{
		if (solve(nstates[i], depth - 1)) {
			print_state(&s);
			return 1;
		}
	}
	return 0;
}

void main()
{
	State s = new_game();
	solve(s, 8);
}