SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 AND people.name IN (
    SELECT name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw" AND people.name IN (
        SELECT name FROM people
        JOIN passengers on passengers.passport_number = people.passport_number
        JOIN flights on flights.id = passengers.flight_id
        JOIN airports on airports.id = flights.destination_airport_id
        WHERE flights.year = 2021 AND
        flights.month = 7 AND
        flights.day = 28 AND
        flights.hour < 9 AND
        airports.full_name = "Fiftyville Regional Airport" AND people.license_plate IN (
            SELECT license_plate FROM people
            
            WHERE year = 2021 AND
            month = 7 AND
            day = 28 AND
            hour = 10 AND
            minute BETWEEN 15 AND 25
            AND activity = "exit"

            )
        )
);