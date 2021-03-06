#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"
#include "MyLayout_N_M_P_OTHER.h"
#include "LayerSwallowTouch.h"

using namespace ui;

class LayerChangeNameEditbox;
class LayerChangeName :public Layer
{
public:
	LayerChangeName();
	virtual~LayerChangeName();
	static LayerChangeName*create(MyLayout_N_M_P_OTHER * data);
	bool init(MyLayout_N_M_P_OTHER * data);
	void changeNameBtnCallback(Ref* pSender, Widget::TouchEventType type); //修改按钮的回调;

	void editBoxReturn(EditBox* editBox);    // 当按下返回按钮或触摸屏幕外部区域时调用, 此时应该取消这次修改;
	void editBoxEditingDidBegin(EditBox* editBox); //当获取输入框时触发的函数;
	void editBoxTextChanged(EditBox* editBox, const std::string& text); //当box里面的文字改变时
	void receiveRemove(EventCustom* event);

	EventListenerTouchOneByOne* touch;
protected:
	CC_SYNTHESIZE_READONLY(LayerChangeNameEditbox*, layerChangeNameEditbox, _LayerChangeNameEditbox);  //确定与新文字输入页面
	MyLayout_N_M_P_OTHER * data;
	ui::Layout * lyChangeName;
	//修改按钮层的触摸函数
	bool onTouchBegan(Touch *touch, Event *unused_event); 
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	//文本输入框层的触摸函数
	//virtual bool onTouchBegan2(Touch *touch, Event *unused_event);
	//virtual void onTouchMoved2(Touch *touch, Event *unused_event);
	//virtual void onTouchEnded2(Touch *touch, Event *unused_event);

	Button* btnChange;  //修改按钮
	bool isBtnChangeMoved = false; //按到修改按钮里是否移动
	bool isLayerCancel = false;   //当前层按其他位置取消时是否移动;

	
	LayerSwallowTouch * layswallowTouch;
//	Layer* layerEdit;    //文本输入框层,子层
//	Button * btnConfirm;  //确定按钮
//	Button * btnCancel;   //取消按钮
//	bool isBtnConfirmMoved; //文本编辑确定按钮按下移动
//	bool isBtnCancelMoved;  //文本编辑取消按钮按下移动



	//以下是测试内容
	void update(float delta);
	bool willRemove = false;
};

