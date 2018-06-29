loop:-
    go,
    %write("Would you like to try again(y/n) ? "),
    response(Reply),
    Reply='n'.
loop.



go:-
    %write("What is the patient's name? "),
    read(Patient),nl,
    hypothesis(Patient, Disease), !,
    write(Patient),
    write(" probably has "),
    write(Disease), nl.

go:-
    write("Sorry, I don't seem to be able to"),
    write(" diagnose the disease."),nl.

 

symptom(Patient, fever):-
   %write("Does "),
    write(Patient),
   %write(" have a fever (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, headache):-
    %write("Does "),
    write(Patient),
    %write(" have a headache (y/n)? "),
    response(Reply),
    Reply='y'.


symptom(Patient, runny_nose):-
    %write("Does "),
    write(Patient),
    %write(" have a runny nose (y/n)? "),
    response(Reply),
    write("has "),
    Reply='y'.

symptom(Patient, rash):-
   %write("Does "),
    write(Patient),
   %write(" have a rash (y/n)? "),
    response(Reply),
    Reply='y'.



symptom(Patient, conjunctivitis):-
    %write("Does "),
    write(Patient),
    %write(" have a conjunctivitis (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, cough):-
    %write("Does "),
    write(Patient),
    %write(" have a cough (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, body_ache):-
    %write("Does "),
    write(Patient),
    %write(" have a body ache (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, chills):-
    %write("Does "),
    write(Patient),
    %write(" have a chills (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, sore_throat):-
    %write("Does "),
    write(Patient),
    %write(" have a sore throat (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, sneezing):-
    %write("Does "),
    write(Patient),
    %write(" have a sneezing (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, swollen_glands):-
    %write("Does "),
    write(Patient),
    %write(" have a swollen glands (y/n)? "),
    response(Reply),
    Reply='y'.

hypothesis(Patient, 'Measles'):-
    symptom(Patient, fever),
    symptom(Patient, cough),
    symptom(Patient, conjunctivitis),
    symptom(Patient, runny_nose),
    symptom(Patient, rash).

hypothesis(Patient, 'German Measle'):-
    symptom(Patient, fever),
    symptom(Patient, headache),
    symptom(Patient, runny_nose),
    symptom(Patient, rash).

hypothesis(Patient, 'Flu'):-
    symptom(Patient, fever),
    symptom(Patient, headache),
    symptom(Patient, body_ache),
    symptom(Patient, conjunctivitis),
    symptom(Patient, chills),
    symptom(Patient, sore_throat),
    symptom(Patient, cough),
    symptom(Patient, runny_nose).

hypothesis(Patient, 'Common Cold'):-
    symptom(Patient, headache),
    symptom(Patient, sneezing),
    symptom(Patient, sore_throat),
    symptom(Patient, chills),
    symptom(Patient, runny_nose).

hypothesis(Patient, 'Mumps'):-
    symptom(Patient, fever),
    symptom(Patient, swollen_glanda).

hypothesis(Patient, 'Chicken Pox'):-
    symptom(Patient, fever),
    symptom(Patient, rash),
    symptom(Patient, body_ache),
    symptom(Patient, chills).

hypothesis(Patient, 'Whooping Cough'):-
    symptom(Patient, cough),
    symptom(Patient, sneezing),
    symptom(Patient, runny_nose).

response(Reply):-
    read(Reply),
    write(Reply),nl.
