# ENVISIONATE: HEAR 2 SEE

Believe it or not fellow Hackers, people go outside! And when they go outside, they can get hurt - especially if they have a visual impairment.

Some insight exists on the challenges that people with visual impairments face when it comes to accidents, though the research is only preliminary. A 2011 survey by Manduchi and Kurniawan at the University of Santa Cruz found that while visually impaired people do like to go out, a substantial amount of respondents reported that accidents required medical treatment AND reduced their confidence as independent travelers. Moreover, only 9% use some kind of technical mobility aid. This means that wearable tech for these latter people represents an untapped market with potential for growth!

With this product, we're bringing tech applications to the people who need it most. Easy-to-use hardware combined with our reliable object-detecting mechanism makes this a cutting-edge device for improving blind people's lives!

## TO DO

- OVERNIGHT: investigate threading more (probably impossible)

### ASAP:

- Figure out how we gonna do this lol
    - Idea so far:
        - Initialize a bunch of shit
        - Each (of 3) ultrasound sensors send a ping (trig) and waits for an echo. They will return to us distance to object in cm (minimal delay)
        - Do some trig and figure out which buzzers to buzz (have someone do trig) - or not lol
        - Buzz buzzers (have a bool for buzzing?)
            - How strong do we buzz??? Have someone determine intensity function. --> turns out only really one intensity
            - Proposed: max buzz <= 25cm, min ~3/3.5m
        - Person supposedly is supposed to dodge obstacle. <3 <333333
        - Continue pinging and turn off buzzers once thing is removed

- Actually make the device and set up the pins

- ~~Ask for McHacks shirt~~ (GOT IT) and make a harness!!!!
    - This is gonna take a lot of crazy arts and crafts skills

### WHENEVER:

- Build pitch (draft under purpose)
    - We need a cool-ass name leell

- Submit our build to the McHacks site by 10am Sun

- if we have time we can register a domain and make a site with HTML and CSS but only if we have extra time (also note that registering a domain takes hours)