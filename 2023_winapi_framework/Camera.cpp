#include "pch.h"
#include "Camera.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

void Camera::Update()
{
	if (_targetObj != nullptr)
	{
		if (_targetObj->GetIsDead()) { _targetObj = nullptr; } // 죽으면 null로 초기화
		else
		{
			_lookAt = _targetObj->GetPos();

			if (KEY_PRESS(KEY_TYPE::UP)) { _lookAt.y -= _targetObj->GetSpeed() * fDT; }
			if (KEY_PRESS(KEY_TYPE::DOWN)) { _lookAt.y += _targetObj->GetSpeed() * fDT; }
			if (KEY_PRESS(KEY_TYPE::LEFT)) { _lookAt.x -= _targetObj->GetSpeed() * fDT; }
			if (KEY_PRESS(KEY_TYPE::RIGHT)) { _lookAt.y += _targetObj->GetSpeed() * fDT; }
		}
	}

	CalDiff();
}

void Camera::CalDiff()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Vec2 center = resolution / 2;

	_diffVec = _lookAt - center;

}
