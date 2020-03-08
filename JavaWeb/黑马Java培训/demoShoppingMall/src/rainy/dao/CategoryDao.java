package rainy.dao;

import java.util.List;

import rainy.domain.Category;
import rainy.domain.Product;

public interface CategoryDao {
	/**
	 * 获取分类信息
	 * @return
	 */
	List<Category> queryCategories();
	/**
	 * 获取某分类的商品列表
	 * @param cid 分类ID
	 * @return
	 */
	List<Product> queryProductsByCategory(String cid, int startIndex, int recordNum);
	/**
	 * 获得该分类下的商品总数
	 * @param cid 分类ID
	 * @return
	 */
	int queryCategoryRecords(String cid);
	void add(Category cate);
	void update(Category cate);
	void delete(String cid);

}
