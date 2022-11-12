SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60 