A small Windows console not-really-a-game I wrote when I was young to see if I could program the basic game mechanic of a character moving around in a world in a console program.

Originally, I redrew the whole output after every processed input, and that didn't really work because it was slow and you could see the output being redrawn, so I had to use these ugly Windows handles, which I didn't like because I struggled with English, there was no good translation for 'handle' into my first language, and (ironically) I found the concept of a handle difficult to grasp.

The game state is kept in the Spielfeld ([IPA: [ˈʃpiːlˌfɛlt]](https://de.wiktionary.org/wiki/Spielfeld), German for 'playing field', or in this case the more fitting 'game board', 'playing ground' or 'sandbox') class which has two variables to save the position of the cursor. I named them 'protagonistX/Y' because that's what this "cursor" represents in your usual 2D bird's-eye view game, and I was struggling to find a better name. 'cursor' was a term I believed to be reserved for the mouse cursor, though that was a perfectly sensible name in this case, of course.

I only rewrote the program to use C++23 print and println instead of cout because output was bugged; all else remains the same as it was in 2011.
