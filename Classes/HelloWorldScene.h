#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	void  update(cocos2d::CCTime dt);
 void  handleUserTouch(cocos2d::CCTouch *touch);
   void loadController(  );
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	enum
	{
		kTop = 1,
		kRight,
		kBot,
		kLeft,
		kArrow
	};
	cocos2d::CCSprite* pTop;
	cocos2d::CCSprite* pRight;
	cocos2d::CCSprite* pBot;
	cocos2d::CCSprite* pLeft;

//	 Cocos2d::CCArray *towerBases;
};

#endif // __HELLOWORLD_SCENE_H__
