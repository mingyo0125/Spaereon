#include "pch.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Object.h"
#include "EventMgr.h"
#include "ItemSpawner.h"
#include "KeyMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "ResMgr.h"
#include "Camera.h"
#include <time.h>
#include "SceneMgr.h"
#include "ExplosionEffect.h"
#include "Scene.h"
#include "ItemEffecter.h"

bool m_isDie;
Vec2 m_vCurPos;

Monster::Monster(Object* target, float speed, int hp)
	: m_target(target), m_fSpeed(speed), m_iHp(hp), hpTex(nullptr)
{
	Object::SetName(L"Monster");
	hpTex = ResMgr::GetInst()->TexLoad(L"HpTex", L"Texture\\Heart_Red_1.bmp");
	m_target = target;
	m_fSpeed = speed;
	m_iHp = hp;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	m_vCurPos = GetPos();
	Vec2 vTargetPos = m_target->GetPos();
	Vec2 moveDir = (vTargetPos - m_vCurPos).Normalize();

	m_vCurPos = m_vCurPos + (moveDir * m_fSpeed);

	SetPos(m_vCurPos);
	GetAnimator()->Update();
}

void Monster::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Bullet")
	{
		//SetDie();
		SetHit();
	}
}

void Monster::ExitCollision(Collider* _pOther)
{
}

void Monster::StayCollision(Collider* _pOther)
{
}

void Monster::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	m_renderPos = Camera::GetInst()->GetRenderPos(vPos);
	int Width = hpTex->GetWidth();
	int Height = hpTex->GetHeight();

	if (m_iHp == 3)
	{
		for (int i = 1; i <= 3; i++)
		{
			TransparentBlt(_dc
				, (int)(m_renderPos.x - vScale.x / 2 * i)
				, (int)(m_renderPos.y - vScale.y - 25)
				, Width, Height, hpTex->GetDC()
				, 0, 0, Width, Height, RGB(255, 255, 255));
		}
	}
	else if (m_iHp == 2)
	{
		for (int i = 1; i <= 2; i++)
		{
			TransparentBlt(_dc
				, (int)(m_renderPos.x - vScale.x / 2 * i)
				, (int)(m_renderPos.y - vScale.y - 25)
				, Width, Height, hpTex->GetDC()
				, 0, 0, Width, Height, RGB(255, 255, 255));
		}
	}
	else
	{
		TransparentBlt(_dc
			, (int)(m_renderPos.x - vScale.x / 2)
			, (int)(m_renderPos.y - vScale.y - 25)
			, Width, Height, hpTex->GetDC()
			, 0, 0, Width, Height, RGB(255, 255, 255));
	}
	

    Component_Render(_dc);
}

void Monster::SetDie()
{
	m_fSpeed = 0;

<<<<<<< HEAD
<<<<<<< HEAD
	srand((unsigned int)time(NULL));
	if (rand() % 5 == 0)
	{
		ItemSpawner* itemSpawner = new ItemSpawner();
		itemSpawner->RandomItemSpawn(m_renderPos);
=======
	ExpEffect* effect = new ExpEffect();
	effect->SetPos(GetPos());
	SceneMgr::GetInst()->GetCurScene()->AddObject(effect, OBJECT_GROUP::DEFAULT);
	EventMgr::GetInst()->DeleteObject(this);

	if (rand() % 5 == 0)
	{
=======
	ExpEffect* effect = new ExpEffect();
	effect->SetPos(m_renderPos);
	SceneMgr::GetInst()->GetCurScene()->AddObject(effect, OBJECT_GROUP::DEFAULT);
	EventMgr::GetInst()->DeleteObject(this);

	if (rand() % 5 == 0)
	{
>>>>>>> parent of 46992be (Merge branch 'King')
		Player* p = (Player*)m_target;
		p->SetUnDestroyedBullet();
	}
	if (rand() % 5 == 1)
	{
		auto dg = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::DEFAULT);
		for (int i = 0; i < dg.size(); i++)
		{
			if (dg[i]->GetName() == L"Effecter")
			{
				ItemEffecter ie = (ItemEffecter*)dg[i];
				ie.EffectToPlayer();
				break;
			}
		}
<<<<<<< HEAD
>>>>>>> d2440e97b2212db3b34f6299acd421751a82ea2d
=======
>>>>>>> parent of 46992be (Merge branch 'King')
	}
}



void Monster::SetHit()
{
	m_iHp -= 1;

	if (m_iHp == 0)
	{
		SetDie();
	}
}
