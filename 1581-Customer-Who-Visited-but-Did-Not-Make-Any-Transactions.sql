select v.customer_id,COUNT(*) as count_no_trans from visits as v
left join transactions as t on t.visit_id=v.visit_id
where t.visit_id IS NULL
Group by customer_id;
