#include "CXPlayer.h"
#include "CKey.h"

void CXPlayer::Update(){
	if (mAnimationIndex == 3){
		if (mAnimationFrame >= mAnimationFrameSize){
			ChangeAnimation(4, false, 30);
		}
	}
	else if (mAnimationIndex == 4){
		if (mAnimationFrame >= mAnimationFrameSize){
			ChangeAnimation(0, true, 60);
		}
	}
	else {
		//�X�y�[�X�L�[�������ƍU�����A�U��������́A���̎p���֖߂��A�ҋ@����
		if (CKey::Once(' ')){
			ChangeAnimation(3, false, 30);
		}	
		//W�L�[��������Ă���Ε����A������Ă��Ȃ���Αҋ@
		else if (CKey::Push('W')){
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
		else if (CKey::Push('D')){
			mRotation.mY -= 2.0f;
		}
	}
	CXCharacter::Update();
}