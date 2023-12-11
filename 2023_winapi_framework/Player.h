#pragma once
#include "Object.h"
class Texture;
class Player :
    public Object
{
public:
    Player();
    ~Player();
private:
    virtual void EnterCollision(Collider* _pOther) override;
    virtual void ExitCollision(Collider* _pOther)  override;
    virtual void StayCollision(Collider* _pOther)  override;
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnDamage(int damage);
    void Die();
private:
    void CreateBullet();
    void TextureLoad();
private:
    Texture* walkRightTex;
    Texture* walkLeftTex;
    Texture* shootLeftTex;
    Texture* shootRightTex;
    Texture* m_pTexIdle;
    Texture* hitTexRight;
    Texture* hitTexLeft;
    Texture* DieTexLeft;
    Texture* DieTexRight;
    Texture* StaticDieTexLeft;
    Texture* StaticDieTexRight;
    Texture* hp1Tex;
    Texture* hp2Tex;
    Texture* hp3Tex;
    Texture* hp4Tex;
    Texture* hp5Tex;
    Texture* hp6Tex;
    int* Hp;
    int MaxHp;
    bool isKeyPressing;
    bool isLeft;
    bool isShooting;
    bool isDie;
    float curTime;
};

