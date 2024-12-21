package dp_05_iterator;

public class ProductIterator implements Iterator{

    private Product[] products;
    private int currentIndex;

    public ProductIterator(Product[] products) {
        this.products = products;
    }

    @Override
    public boolean hasNext() {
        return currentIndex < products.length;
    }

    @Override
    public Product next() {
        Product b = products[currentIndex];
        currentIndex++;
        return b;
    }
}
