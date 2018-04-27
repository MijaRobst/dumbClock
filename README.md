# dumbClock

This script is a clock that ticks with the translation of the Earth as reference.

The translation period of the Earth is 365.25 days* = 31,557,600 seconds. However, we round that to 365 days = 31,536,000 seconds. There is a difference of 21,600 seconds, that constitutes a day every four years. A tsecond (translation second) will be the unit of measure of time that makes each year (time the Earth takes to orbit the sun) have exactly 365 days. That way, a tsecond will measure (1 + 1 / 1460) seconds.

In other words, the expression of time in tseconds is ts = s + s / 1460.

Starting on March 1st of a leap year, this clock counts tseconds by performing calculations on Unix time.

It displays the time every second to avoid error in counting tseconds.

\* In fact, a year is 365 days, 5 hours, 48 minutes and 45 seconds, so the clock would not sync every four years. As that is one of the beauties of this project, it will be assumed that a year is 365.25 days long.
