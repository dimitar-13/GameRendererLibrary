#include "Rendererpch.h"
#include "Component.h"
#include"GameObject/GameObject.h"

SpriteRenderer::GameObject SpriteRenderer::Component::GetGameObj()
{
    return { entity };
}
void SpriteRenderer::Component::SetGameObjectEntity(ECSTypes::Entity ent)
{
    this->entity = ent;
}
