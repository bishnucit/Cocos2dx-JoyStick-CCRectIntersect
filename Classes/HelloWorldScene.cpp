#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
	char fontName[13] = {"airborne.ttf"};
	char myText[21] = {"Rendering"};
    CCLabelTTF* pLabel = CCLabelTTF::create(myText, fontName, 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(350,50));
	pLabel->setColor(cocos2d::ccRED);
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

   this->setTouchEnabled(true);
   
   /*this->schedule( schedule_selector(handleUserTouch) );*/  
    CCSprite* pSprite = CCSprite::create("bg.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
	 
	//The code starts here.. all the assets are done by me and plist file and sprite file was generated with sprite packer.
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("SpriteColl1.plist");
	CCSpriteBatchNode *spriteSheet = CCSpriteBatchNode::create("SpriteColl1.png");
	this->addChild(spriteSheet);
	 

	CCSprite *sprite = CCSprite::createWithSpriteFrameName("Sprite1.png");
	this->addChild(sprite);
    sprite->setPosition(ccp(400,200));
	CCArray *moveFrames = CCArray::createWithCapacity(15);
	char str[100] = {0};
for (int i = 1; i <= 4; i++) 
{
	sprintf(str, "Sprite%d.png", i);
    CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);

    moveFrames->addObject(pFrame);
}
CCAnimation *animation = CCAnimation::createWithSpriteFrames(moveFrames, 0.3f);
    // 14 frames * 1sec = 14 seconds
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));

	
	
	this->loadController();
		 
    return true;
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
}

void HelloWorld::loadController()
{
               
 
        pTop = CCSprite::create("Top.png"  );
        pTop ->setPosition(ccp(100,120));
        this->addChild(pTop,1,kTop);
       
 
        pRight = CCSprite::create("Right.png" );
        pRight ->setPosition(ccp(150,70));
        this->addChild(pRight,1,kRight);
       
 
        pBot = CCSprite::create("Bot.png" );
        pBot ->setPosition(ccp(100,30));
        this->addChild(pBot,1,kBot);
       
 
        pLeft = CCSprite::create("Left.png" );
        pLeft ->setPosition(ccp(50,80));
        this->addChild(pLeft,1,kLeft);
       
         
		CCSprite *arrow = CCSprite::create("arrow.png");
		
		arrow->setPosition(ccp(220,150));
		this->addChild(arrow,1,kArrow);

		

		 
}
 
 
 
 
 
void HelloWorld::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    // get the touch object
    CCTouch* touch = (CCTouch *)touches->anyObject();
    this->handleUserTouch(touch);
}
 
 
void  HelloWorld::handleUserTouch(CCTouch *touch)
{
	  CCSprite *pArrow= (CCSprite*)getChildByTag(kArrow);
	 
         CCPoint location = touch->getLocation();
        location = CCDirector::sharedDirector()->convertToGL(location);
       float x =(float) location.x;
	   float y =(float) location.y;
	   CCSprite *pImage2= (CCSprite*)getChildByTag(kTop);
	   CCSprite *pImage1= (CCSprite*)getChildByTag(kRight);
       CCSprite *pImage3= (CCSprite*)getChildByTag(kBot);
	   CCSprite *pImage4= (CCSprite*)getChildByTag(kLeft);

		CCRect topRect = CCRectMake(pImage2->getPosition().x,pImage2->getPosition().y,50,50);
		CCRect rightRect = CCRectMake(pImage1->getPositionX(),pImage1->getPositionY(),50,50);
		CCRect botRect = CCRectMake(pImage3->getPositionX(),pImage3->getPositionY(),50,50);
	    CCRect leftRect = CCRectMake(pImage4->getPositionX(),pImage4->getPositionY(),50,50);

	CCRect pointRect = CCRectMake(x,y,50,50);

	if(topRect.intersectsRect(pointRect))
 
        {
			 
                pArrow->setPositionX(pArrow->getPositionX());
                pArrow->setPositionX(pArrow->getPositionY()+10);
				
        }
 
         else if
                 (rightRect.intersectsRect(pointRect))
         {
                 pArrow->setPositionX(pArrow->getPositionX()+10);
                pArrow->setPositionX(pArrow->getPositionY());
				
         }
 
          else if
                   (botRect.intersectsRect(pointRect))
         {
                 pArrow->setPositionX(pArrow->getPositionX());
                pArrow->setPositionX(pArrow->getPositionY()-10);
				
         }
          else if
                  (leftRect.intersectsRect(pointRect))
          {
                   pArrow->setPositionX(pArrow->getPositionX()-10);
                pArrow->setPositionX(pArrow->getPositionY());
				
          }
        
}