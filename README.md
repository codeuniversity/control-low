# Low Level Controller

## Overview

![](/Users/selmaillig/Desktop/Screen Shot 2019-11-14 at 17.10.53.png)

The control-low repository is a collection of different programs. 

The diagram focusses on the leg_message directory, the actual low-level-controller. The purpose of the Low level controller is translate gait actions to servo movements. The other programs are stored here for debugging purposes.

The LLC controls a single leg, constiting of three servos (Hip_Joint, Knee_Joint, Foot_Joint). The LLC implements the gait actions in servo movements. The gait actions are send by the gait controller through Nervo: "move up", "move down" or "rotate by x degree".
[Nervo](https://github.com/codeuniversity/nervo) is a tools to read and write messages to an Arduino and to flash programs on an Arduino.

Messages are shared between Nervo and the LLC using Serial communication through USB.

## Setup

Flash program on Arduino. 

Connect Arduino with robot leg.

## Usage



## Program Structure

internal processes

