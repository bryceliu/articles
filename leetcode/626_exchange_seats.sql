select a.id, coalesce(b.student, a.student) as student from seat a left join seat b on ((a.id+1)^1)-1 = b.id order by a.id;
