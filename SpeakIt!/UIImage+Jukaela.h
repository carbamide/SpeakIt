//
//  UIImage+Jukaela.h
//  JukaelaCore
//
//  Created by Josh on 8/22/13.
//  Copyright (c) 2013 Jukaela Enterprises.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

@import Foundation;
@import UIKit;

/**
 UIImage catagory, with all manor of neat things
 */
@interface UIImage (Jukaela)

///---------------------------------------
/// @name Class Methods
///---------------------------------------

/** Saves UIImage to users Documents folder
 
 Saves a given UIImage to the user's Documents folder on an async background thread
 
 @param image The 'UIImage' to save
 @param filename 'NSString' of what to name the file
 */
+(void)saveImage:(UIImage *)image withFileName:(NSString *)filename;

/** Normalize UIImage for use in simulator
 
 Use of this call should be ifdefed to only be called in the iOS Simulator
 
 @param theImage The 'UIImage' to normalize
 @return 'UIImage' that has been normalized
 */
+(UIImage *)normalize:(UIImage *)theImage;

/** Create 'UIImage' of the specified 'UIColor'
 
 @param color The 'UIColor' to create the 'UIImage' from
 @return 'UIImage' that is the specified 'UIColor'
 */
+(UIImage *)getImageFromColor:(UIColor *)color;

///---------------------------------------
/// @name Instance Methods
///---------------------------------------

/** Check if UIImage has an alpha channel
 @return 'BOOL' type
 */
-(BOOL)hasAlpha;

/** Returns image with alpha channel
 @return 'UIImage' with alpha channel
 */
-(UIImage *)imageWithAlpha;

/** Create a transparent border on 'UIImage'
 @param borderSize Size of the requested border
 @return 'UIImage' with a transparent border
 */
-(UIImage *)transparentBorderImage:(NSUInteger)borderSize;

/** Crop image to rect
 @param bounds The bounds to crop the image to
 @return 'UIImage' cropped to requested bounds
 */
-(UIImage *)croppedImage:(CGRect)bounds;

/** Thumbnail image
 
 Returned image must have the 'opaque' property set to no, or the border won't show
 
 @param thumbnailSize The reqested return image size
 @param borderSize The size of the border
 @param cornerRadius If set, the image's corners will be rounded to the given radius
 @param quality Interpolation quality
 @return 'UIImage' with requested attributes
 */
-(UIImage *)thumbnailImage:(NSInteger)thumbnailSize
         transparentBorder:(NSUInteger)borderSize
              cornerRadius:(NSUInteger)cornerRadius
      interpolationQuality:(CGInterpolationQuality)quality;

/** Resize UIImage
 
 This method doesn't have the problem that some resizing methods from other frameworks have, such as discoloration
 
 @param newSize The requested size
 @param quality Interpolation quality
 @return 'UIImage' with requested attributes.
 */
-(UIImage *)resizedImage:(CGSize)newSize
    interpolationQuality:(CGInterpolationQuality)quality;

/** Resized image with content mode
 
 This method doesn't have the problem that some resizing methods from other frameworks have, such as discoloration

 @param contentMode The 'UIViewContentMode' of the requested returned image
 @param bounds The resized bounds
 @param quality Interpolation quality
 */
-(UIImage *)resizedImageWithContentMode:(UIViewContentMode)contentMode
                                 bounds:(CGSize)bounds
                   interpolationQuality:(CGInterpolationQuality)quality;

/** Scale and rotate an image
 @param image The image to scale and rotate
 @param maxSize The max size to in pixels
 @return 'UIImage' that is scaled and rotated
 */
-(UIImage *)scaleAndRotateImage:(UIImage *)image withMaxSize:(int)maxSize;

/** The transform orientation of the image with the requested new size
 @param newSize The requested new size
 @return CGAffineTransform to apply
 */
-(CGAffineTransform)transformForOrientation:(CGSize)newSize;

/** Round the corners of the 'UIImage' and set the border size
 @param cornerSize The radius of the corner, in pixels
 @param borderSize the requested border size
 @return 'UIImage' with the requested attributes
 */
-(UIImage *)roundedCornerImage:(NSInteger)cornerSize borderSize:(NSInteger)borderSize;

/** Apply light blur effect
 
 This effect is similar to the effect produced by a transparent 'UIToolbar' or 'UINavigationBar' in iOS 7.
 
 @return 'UIImage' with effect applied.
 */
- (UIImage *)applyLightEffect;

/** Apply extra-light blur effect
 
 This effect is similar to the effect produced by a transparent 'UIToolbar' or 'UINavigationBar' in iOS 7.
 
 @return 'UIImage' with effect applied.
 */
- (UIImage *)applyExtraLightEffect;

/** Apply dark blur effect
 
 This effect is similar to the effect produced by a transparent 'UIToolbar' or 'UINavigationBar' in iOS 7.
 
 @return 'UIImage' with effect applied.
 */
- (UIImage *)applyDarkEffect;

/** Apply tint effect
 
 Tints the 'UIImage' to the given tint 'UIColor'
 
 @param tintColor The color that you want the 'UIImage' tinted to
 
 @return 'UIImage' with effect applied.
 */
- (UIImage *)applyTintEffectWithColor:(UIColor *)tintColor;

/** Much finer control of tint, blur and saturation effect
 
 This effect can be made to be similar to the effect produced by a transparent 'UIToolbar' or 'UINavigationBar' in iOS 7.
 
 @param blurRadius The blur radius for the Gaussian blur
 @param tintColor The color that you want the 'UIImage' tinted to
 @param saturationDeltaFactor The delta that you want the saturation of the image increased
 @param maskImage 'UIImage' to mask the returned 'UIImage' to
 @return 'UIImage' with effect applied.
 */
- (UIImage *)applyBlurWithRadius:(CGFloat)blurRadius tintColor:(UIColor *)tintColor saturationDeltaFactor:(CGFloat)saturationDeltaFactor maskImage:(UIImage *)maskImage;

@end
