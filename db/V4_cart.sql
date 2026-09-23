CREATE TABLE cart_items (
    id SERIAL PRIMARY KEY,
    buyer_id INT NOT NULL REFERENCES users(id),
    product_id INT NOT NULL REFERENCES products(id),
    quantity INT NOT NULL,
    UNIQUE(buyer_id, product_id)
);