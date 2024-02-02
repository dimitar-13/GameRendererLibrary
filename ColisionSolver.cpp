#include "Rendererpch.h"
#include "ColisionSolver.h"

void SpriteRenderer::ColisionSolver::SolveForColiders()
{
	for (Colision& colision:colisions)
	{
		if (colision.colider1.isTrigger || colision.colider2.isTrigger)
		{
			//Call trigger event
		}
		else
		{

		}
	}
}
