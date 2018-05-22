go:-
    read(City),nl,
    location(City,State),
    write(City),
    write("    "),
    write(State),nl,!,

location("Jackson","MS").
location("Washington","DC").
location("Raleigh","NC").

