# Write your MySQL query statement below
select products.product_name , sum(orders.unit) as unit from products 
inner join orders  on products.product_id=Orders.product_id 
where orders.order_date between '2020-02-01' and  '2020-02-29' 
group by products.product_id Having sum(orders.unit)>=100;