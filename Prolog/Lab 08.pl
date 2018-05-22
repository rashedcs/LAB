go:-
    read(Patient),
    hypothesis(Patient, Disease),
    write(Patient),
    %write(" probably has "),
    write(Disease),
    write("."),nl.

go:-
    write("Sorry, I don't seem to be able to"),
    write(" diagnose the disease."),nl.

symptom(Patient, fever):-
    %write("Does "),
    write(Patient),
    %write(" have a fever (y/n)? "),
    response(Reply),
    Reply='y'.y.
    

symptom(Patient, rash):-
    %write("Does "),
    write(Patient),
    %write(" have a rash (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, headache):-
   % write("Does "),
    write(Patient),
    %write(" have a headache (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, runny_nose):-
    %write("Does "),
    write(Patient),
   %write(" have a runny nose (y/n)? "),
    response(Reply),
    Reply='y'.

symptom(Patient, conjunctivitis):-
    %write("Does "),
    write(Patient),
    %write(" have a conjunctivitis (y/n)? "),
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
