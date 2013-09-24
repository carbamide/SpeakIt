//
//  ViewController.m
//  SpeakIt!
//
//  Created by Joshua Barrow on 9/23/13.
//  Copyright (c) 2013 Jukaela Enterprises. All rights reserved.
//

#import "ViewController.h"
#import "UIImage+Jukaela.h"

#pragma mark - 
#pragma mark Interface

@interface ViewController ()

@property (strong, nonatomic) AVSpeechSynthesizer *synthesizer;
@property (nonatomic) float speechSpeed;
@property (nonatomic) float speechPitch;

@end

static float const kDefaultSpeechSpeed = 0.5;
static float const kDefaultSpeechPitch = 1.0;

#pragma mark -
#pragma mark Implementation

@implementation ViewController

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    [[self speechTextView] setBackgroundColor:[UIColor clearColor]];
    
    UIImageView *backgroundView = [[UIImageView alloc] initWithFrame:[[self view] bounds]];
    UIImage *backgroundImage = [[UIImage imageNamed:@"background.png"] applyLightEffect];
    
    [backgroundView setImage:backgroundImage];
    
    [[self view] insertSubview:backgroundView atIndex:0];
    
    [self setSynthesizer:[[AVSpeechSynthesizer alloc] init]];
    
    [[self synthesizer] setDelegate:self];
    
    [[self speechTextView] becomeFirstResponder];
    
    [self setSpeechSpeed:kDefaultSpeechSpeed];
    [self setSpeechPitch:kDefaultSpeechPitch];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - 
#pragma mark IBActions

- (IBAction)speakItAction:(id)sender
{
    if ([[[[self speakItButton] titleLabel] text] isEqualToString:@"Speak!"]) {
        AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:[[self speechTextView] text]];
        [utterance setRate:_speechSpeed];
        [utterance setPitchMultiplier:_speechPitch];
        
        [[self synthesizer] speakUtterance:utterance];
    }
    else {
        [[self synthesizer] stopSpeakingAtBoundary:AVSpeechBoundaryWord];
    }
}

- (IBAction)speedAction:(id)sender
{
    float speed = [(UISlider *)sender value];
    
    [self setSpeechSpeed:speed];
}

- (IBAction)pitchAction:(id)sender
{
    float pitch = [(UISlider *)sender value];
    
    [self setSpeechPitch:pitch];
}

#pragma mark - 
#pragma mark Helpers

- (void)enableSpeaking
{
    [[self speakItButton] setTitle:@"Speak!" forState:UIControlStateNormal];
    
    [[self speedSlider] setEnabled:YES];
    [[self pitchSlider] setEnabled:YES];
}

- (void)disableSpeaking
{
    [[self speakItButton] setTitle:@"Stop" forState:UIControlStateNormal];
    
    [[self speedSlider] setEnabled:NO];
    [[self pitchSlider] setEnabled:NO];
}

#pragma mark - 
#pragma mark AVSpeechSynthesizerDelegate

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didStartSpeechUtterance:(AVSpeechUtterance *)utterance
{
    [self disableSpeaking];
}

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didCancelSpeechUtterance:(AVSpeechUtterance *)utterance
{
    [self enableSpeaking];
}

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didFinishSpeechUtterance:(AVSpeechUtterance *)utterance
{
    [self enableSpeaking];
}

@end
