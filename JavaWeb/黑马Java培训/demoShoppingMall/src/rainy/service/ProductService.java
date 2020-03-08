package rainy.service;

import java.util.List;

import rainy.domain.PageModel;
import rainy.domain.Product;

public interface ProductService {
	/**
	 * 获取前9个最新热门商品
	 * @return
	 */
	List<Product> getHotProducts();

	/**
	 * 根据pid获取商品
	 * @param pid
	 * @return
	 */
	Product getProductByPid(String pid);

	PageModel getProductsByPage(int currentPage);

	void updateProduct(Product prod);

	void addProduct(Product prod);
}
