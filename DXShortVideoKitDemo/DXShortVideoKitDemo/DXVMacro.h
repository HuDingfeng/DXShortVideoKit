//
//  DXVMacro.h
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#ifndef DXVMacro_h
#define DXVMacro_h

#pragma mark size definition
#define kdxvScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define kdxvScreenHeight [UIScreen mainScreen].bounds.size.height
#define kdxvTabBarHeight 49
#define kdxvNavHeight 64

#pragma mark color definition
#define kdxvClearColor [UIColor clearColor]
#define kdxvWhite [UIColor whiteColor]
#define kdxvBlack [UIColor blackColor]
#define kdxvBlack242 [UIColor colorWithRed:242/255.0 green:242/255.0 blue:242/255.0 alpha:1]
#define kdxvPure(x) [UIColor colorWithRed:x/255.0f green:x/255.0f blue:x/255.0f                                                                                  alpha:1.0]
#define kdxvRGB(x,y,z) [UIColor colorWithRed:x/255.0f green:y/255.0f blue:z/255.0f                                                                                  alpha:1.0]
#define kdxvRGBA(x,y,z,a) [UIColor colorWithRed:x/255.0f green:y/255.0f blue:z/255.0f                                                                                  alpha:a]
#define kdxvColorFromHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define kdxvNavigationColor [UIColor colorWithRed:55/255.0 green:70/255.0 blue:101/255.0 alpha:1]

#define kdxvBackColor kdxvRGB(242, 242, 242)
#define kdxvTextColor kdxvRGB(39,37,54)
#define kdxvTextLightColor kdxvRGB(153, 153, 153)
#define kdxvLightBlue kdxvRGB(95,182,215)
#define kdxvDarkBlue kdxvRGB(46, 57, 89)
#define kdxvBlue kdxvRGB(48, 69, 99)
#define kdxvGreen kdxvRGB(63, 182, 90)
#define kdxvOrange kdxvRGB(224, 172, 97)
#define kdxvPink kdxvRGB(238, 83, 151)
#define kdxvPurple kdxvRGB(193, 122, 240)
#define kdxvRed kdxvRGB(253,101,94)

#pragma mark font definition
//@"HelveticaNeue"
//@"HelveticaNeue-Thin"
//[UIFont boldSystemFontOfSize:x]
#define kdxvBoldSystemFont(x) [UIFont fontWithName:@"HelveticaNeue" size:x]//HelveticaNeue-UltraLight
#define kdxvNumberFontType(x) [UIFont fontWithName:@"HelveticaNeue-Thin" size:x]//[UIFont fontWithName:@"Heiti SC" size:x]
#define kdxvNavFont(x) [UIFont fontWithName:@"HelveticaNeue-CondensedBlack" size:x]

#pragma mark -- system definition
#define kdxvIOS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define kdxvIOS_8_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

#define WeakSelf(weakSelf)  __weak __typeof(&*self)weakSelf = self
#define WEAKSELF  typeof(self) __weak weakSelf=self;


#pragma mark nslog definition
#ifdef DEBUG
#define DLog(...) NSLog(__VA_ARGS__)

#else
#define DLog(...)
#endif

#pragma main thread definition
#define kMainQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

#if TARGET_IPHONE_SIMULATOR
#define SIMULATOR 1
#elif TARGET_OS_IPHONE
#define SIMULATOR 0
#endif

#endif /* DXVMacro_h */
