package rainy.dao;

import java.util.List;

import rainy.domain.Product;

public interface ProductDao {
	/**
	 * 获取前9个热门最新商品
	 * @return
	 */
	List<Product> queryHotProducts();
	/**
	 * 根据pid获取商品
	 * @param pid 
	 * @return
	 */
	Product queryProductByPid(String pid);
	int queryProductRecords();
	List<Product> queryProductsByPage(int startIndex, int pageSize);
	void update(Product prod);
	void add(Product prod);
}
