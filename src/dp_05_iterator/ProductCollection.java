
package dp_05_iterator;

public class ProductCollection {

    private Product[] products;

    public ProductCollection(Product[] products) {
        this.products = products;
    }

    public ProductIterator getIterator() {
        return new ProductIterator(products);
    }
}
