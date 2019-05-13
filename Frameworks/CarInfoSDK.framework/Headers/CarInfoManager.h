//
//  BuyManager.h
//  FindCarSDK
//
//  Created by 王鹏飞 on 2019/2/19.
//  Copyright © 2019 chehang168. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CarInfoAFUrlType) {
    CarInfoAFUrlTypeDebug = 0,
    CarInfoAFUrlTypeDePre = 1,
    CarInfoAFUrlTypeDeRelease = 2
};


@protocol CarInfoManagerDelegate <NSObject>

@optional
/** 
 @param array 图片URL数组
 */
-(void)pushToShowImgs:(NSArray*)array;


/**
 @param array 需要隐藏Bar的类名
 */
-(void)carSdkBarHiddenWithVC:(NSArray*)array;


@required
/**
 @return 返回设备信息结合
 */
-(NSDictionary*)carSdkGetDeviceInfo;

@end

@interface CarInfoManager : NSObject
@property(weak,nonatomic)id<CarInfoManagerDelegate>delegate;
@property(assign,nonatomic) CarInfoAFUrlType carInfoAfUrlType;
@property(readonly,strong,nonatomic) NSString *HTTP;
@property(readonly,strong,nonatomic) NSString *HTML_HTTP; 
/**
 用户信息
 */
@property(strong,nonatomic) NSDictionary *userDic;

/**
 导航条按钮颜色
 */
@property(strong,nonatomic) UIColor *barColor;


+ (instancetype)shareManager;

/**
 去寻车首页
 */
-(void)pushToCarInfoVC;

@end

NS_ASSUME_NONNULL_END
