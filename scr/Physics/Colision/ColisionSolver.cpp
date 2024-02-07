#include "Rendererpch.h"
#include "ColisionSolver.h"

void SpriteRenderer::ColisionSolver::SolveColision(Colision colision)
{
	if (colision.colider1->isTrigger || colision.colider2->isTrigger) return;
	//Colision on X
	if (colision.colider1->max.x >= colision.colider2->min.x &&
		colision.colider1->max.x <= colision.colider2->max.x)
	{

	}
	
}

glm::vec2 SpriteRenderer::ColisionSolver::FindColisionNormal(Colider colider1,Colider colider2)
{
	glm::vec2 colisionOnX = colider1.max.x == colider2.min.x ||
							colider1.min.x == colider2.max.x ? glm::vec2(1,0):glm::vec2(0);
	glm::vec2 colisionOnY = colider1.max.y == colider2.min.y ||
							colider1.min.y == colider2.max.y ? glm::vec2(0, 1) : glm::vec2(0);
	return colisionOnX + colisionOnY;
}
