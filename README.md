# ❤️ A little heart for my love

Kitten, thank you for everything. I really love you, and I value you so much.
I want to listen to you and respect your opinion. I'm really trying, and I hope it's working.

Very soon it'll be 5 months since we started talking, and we've already been together for a little over 2 months!
Tomorrow, October 2, 2026, it will be 2 months and 1 week since we became a couple.
I won't congratulate you in advance - it's bad luck

I love you so much, and I want to become better for you. Much, much better.
I want to learn to understand you even more, and to keep being one with you - one soul.

By the way!!! Happy October 1st, my sweetheart! Your favorite winter is almost here,
and we're going to have snowball fights and build snowmen!

On October 3, 2026, I'll make a commit with a small addition to this surprise - look forward to it!

I love you ❤️

## Here's the promised update!!!

UPD. Here it is, just like I promised!!! A few commits and a new version of heart.exe - I hope you like it.
Once again, happy 5 months, my kitten! I love you!

P.S. Delete the old heart.exe so the names don't conflict.

And one more thing - I love you 💜

## How to open it

1. Go to [Releases](https://github.com/sedrias/heart/releases/latest)
2. Download **heart.exe**
3. Double-click it
4. If Windows shows a blue window "Windows protected your PC",
   click **More info** → **Run anyway** (it's safe, I promise 🙂)
5. To stop it, just close the window

## How it works

- The heart shape comes from a math formula:
  x = 16·sin³(t), y = 13·cos(t) − 5·cos(2t) − 2·cos(3t) − cos(4t)
- Words appear at random points on the curve, slowly glow and fade away
- The heart beats: its size follows sin(t), and the name in the center glows in the same rhythm
- Half of the words are pink, half are purple
- The piggy in the middle is pixel art: a small text map where every pixel
  is painted with a background color
- Colors are drawn with ANSI escape codes, ~60 frames per second
- Written in C++23

## Build

    cmake --preset windows-gcc-debug
    cmake --build --preset windows-gcc-debug

Made with ❤️ for my love by sedrias