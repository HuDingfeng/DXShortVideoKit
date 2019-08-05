//
//  DXVProgressView.h
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DXVProgressView : UIView

-(instancetype)initWithFrame:(CGRect)frame minTime:(CGFloat)minTime maxTime:(CGFloat)maxTime;

-(void)updateProgressWithProgress:(CGFloat)progress;
-(void)pauseProgress;
-(void)resetProgress;

-(void)willDeleteLastProgressView;
-(void)cancelDeleteLastProgressView;
-(void)deleteAllProgressViews;
-(void)deleteLastProgressView;
@end

NS_ASSUME_NONNULL_END
