package dp_05_iterator;
public class IteratorTest {
    public static void main(String[] args) {
        Product products[] = {new Product("abc"), new Product("def"), new Product("gh")};
        ProductCollection col = new ProductCollection(products);
        ProductIterator it = col.getIterator();
        while (it.hasNext()) {
            Product b = it.next();
            System.out.println(b.getTitle());
        }
    }
}
