#include "CXPlayer.h"
#include "CKey.h"
#include "CMatrix.h"

void CXPlayer::Update(){
	//W�L�[��������Ă���Ε����A������Ă��Ȃ���Αҋ@
	if (CKey::Push('W')){
		ChangeAnimation(1, true, 60);
		mPosition += CVector(0.0f, 0.0f, 0.1f)*mMatrixRotate;
	}
	else{
		ChangeAnimation(0, true, 60);
	}
	//A�L�[��������Ă���΁AY���̉�]�l��2���Z����
	if (CKey::Push('A')){
		mRotation.mY += 2.0f;
	}
	//D�L�[��������Ă���΁AY���̉�]�l��2���Z����
	if (CKey::Push('D')){
		mRotation.mY -= 2.0f;
	}
	CXCharacter::Update();
}