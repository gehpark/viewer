#!/bin/sh

#  hello_world.sh
#  test
#
#  Created by Grace Park on 8/22/13.
#  Copyright (c) 2013 Grace Park. All rights reserved.

echo "Hello, world!"

# particle#, partizle_size, wind_left, _right, _up, _down, particle_mode, diffusitivity, interaction, obstacle#, obstacle_size, oscillation, amplitude, osbtacle_mode, dist, per_row, run_tim

##################################
##          Control             ##
##################################

echo "starting control 1"

./viewer 100000 .01 0 0 0 0 Discrete 0 Stick 0 0 Together 0 Circle 0 0 120 control1

echo "completed"

echo "starting control 2"

./viewer 100000 .01 0 0 0 0 Continuous 0 Stick 0 0 Together 0 Circle 0 0 120 control2

echo "completed"




##################################
##         Disappear            ##
##################################

echo "starting Disappear 1"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 4 .06 Off 0 Grid .3 2 120 Disappear1

echo "completed"

echo "starting Disappear 2"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Off 0 Grid .3 4 120 Disappear2

echo "completed"

echo "starting Disappear 1b"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 4 .06 Off 0 Grid .5 2 120 Disappear1b

echo "completed"

echo "starting Disappear 2b"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Off 0 Grid .5 4 120 Disappear2b

echo "completed"

echo "starting Disappear 3"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 5 .06 Off 0 Circle .5 0 120 Disappear3

echo "completed"

echo "starting Disappear 4"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 10 .06 Off 0 Circle .5 0 120 Disappear4

echo "completed"

echo "starting Disappear 5"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Together 0.01 Grid .5 4 120 Disappear5

echo "completed"

echo "starting Disappear 6"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Alternate 0.01 Grid .5 4 120 Disappear6

echo "completed"

echo "starting Disappear 7"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Tiered 0.01 Grid .5 4 120 Disappear7

echo "completed"

echo "starting Disappear 8"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Tiered 0.04 Grid .5 4 120 Disappear8

echo "completed"

echo "starting Disappear 9"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Together 0.01 Circle .5 4 120 Disappear9

echo "completed"

echo "starting Disappear 10"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Alternate 0.01 Circle .5 4 120 Disappear10

echo "completed"

echo "starting Disappear 11"

./viewer 100000 .01 0 0 0 0 Discrete 0 Disappear 12 .06 Tiered 0.01 Grid .5 4 120 Disappear11

echo "completed"




##################################
##         Stick                ##
##################################
echo "starting Stick 1"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 4 .06 Off 0 Grid .3 2 120 Stick1

echo "completed"

echo "starting Stick 2"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Off 0 Grid .3 4 120 Stick2

echo "completed"

echo "starting Stick 1b"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 4 .06 Off 0 Grid .5 2 120 Stick1b

echo "completed"

echo "starting Stick 2b"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Off 0 Grid .5 4 120 Stick2b

echo "completed"

echo "starting Stick 3"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 5 .06 Off 0 Circle .5 0 120 Stick3

echo "completed"

echo "starting Stick 4"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 10 .06 Off 0 Circle .5 0 120 Stick4

echo "completed"

echo "starting Stick 5"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Together 0.01 Grid .5 4 120 Stick5

echo "completed"

echo "starting Stick 6"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Alternate 0.01 Grid .5 4 120 Stick6

echo "completed"

echo "starting Stick 7"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Tiered 0.01 Grid .5 4 120 Stick7

echo "completed"

echo "starting Stick 8"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Tiered 0.04 Grid .5 4 120 Stick8

echo "completed"

echo "starting Stick 9"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Together 0.01 Circle .5 4 120 Stick9

echo "completed"

echo "starting Stick 10"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Alternate 0.01 Circle .5 4 120 Stick10

echo "completed"

echo "starting Stick 11"

./viewer 1000 .01 0 0 0 0 Discrete 0 Stick 12 .06 Tiered 0.01 Grid .5 4 120 Stick11

echo "completed"




##################################
##         Reflect              ##
##################################

echo "starting Reflect 1"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 4 .06 Off 0 Grid .3 2 120

echo "completed"

echo "starting Reflect 2"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Off 0 Grid .3 4 120

echo "completed"

echo "starting Reflect 1b"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 4 .06 Off 0 Grid .5 2 120

echo "completed"

echo "starting Reflect 2b"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Off 0 Grid .5 4 120

echo "completed"

echo "starting Reflect 3"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 5 .06 Off 0 Circle .5 0 120

echo "completed"

echo "starting Reflect 4"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 10 .06 Off 0 Circle .5 0 120

echo "completed"

echo "starting Reflect 5"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Together 0.01 Grid .5 4 120

echo "completed"

echo "starting Reflect 6"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Alternate 0.01 Grid .5 4 120

echo "completed"

echo "starting Reflect 7"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Tiered 0.01 Grid .5 4 120

echo "completed"

echo "starting Reflect 8"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Tiered 0.04 Grid .5 4 120

echo "completed"

echo "starting Reflect 9"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Together 0.01 Circle .5 4 120

echo "completed"

echo "starting Reflect 10"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Alternate 0.01 Circle .5 4 120

echo "completed"

echo "starting Reflect 11"

./viewer 100000 .01 0 0 0 0 Discrete 0 Reflect 12 .06 Tiered 0.01 Grid .5 4 120

echo "completed"
