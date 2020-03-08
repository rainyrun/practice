package rainy.dao.impl;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import rainy.dao.ProductDao;
import rainy.domain.Product;

public class ProductDaoImpl implements ProductDao {
	private static ComboPooledDataSource ds = new ComboPooledDataSource();
	private static QueryRunner runner = new QueryRunner(ds);

	@Override
	public List<Product> queryHotProducts() {
		// sql语句
		String sqlQueryHots = "select * from product where is_hot = 1 and pflag = 0 order by pdate desc limit 8;";
		// 结果集
		List<Product> hotProducts = null;
		try {
			hotProducts = runner.query(sqlQueryHots, new BeanListHandler<Product>(Product.class));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return hotProducts;
	}

	@Override
	public Product queryProductByPid(String pid) {
		// sql语句
		String sqlQueryByPid = "select * from product where pid = ?;";
		// 结果
		Product prod = null;
		try {
			prod = runner.query(sqlQueryByPid, new BeanHandler<Product>(Product.class), pid);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return prod;
	}

	@Override
	public int queryProductRecords() {
		// sql
		String sqlQueryProdcutRecords = "select count(*) from product;";
		Long result = 0L;
		// 查询
		try {
			result = (Long) runner.query(sqlQueryProdcutRecords, new ScalarHandler());
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return result.intValue();
	}

	@Override
	public List<Product> queryProductsByPage(int startIndex, int pageSize) {
		// sql
		String sqlQueryByPage = "select * from product limit ?, ?;";
		// 参数
		Object[] params = { startIndex, pageSize };
		// 查询
		List<Product> products = null;
		try {
			products = runner.query(sqlQueryByPage, new BeanListHandler<Product>(Product.class), params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return products;
	}

	@Override
	public void update(Product prod) {
		// 商品：商品名、市场价格、促销价格、图片地址、缩略图地址、上架时间、是否热门、描述、标记（是否下架）、商品分类ID（外键）
		// sql
		String sqlUpdate = "update product set pname = ?, market_price = ?, shop_price = ?, pimage = ?, pimage_short = ?, pdate = ?, is_hot = ?, pdesc = ?, pflag = ?, cid = ? where pid = ?;";
		// 参数
		Object[] params = { prod.getPname(), prod.getMarket_price(), prod.getShop_price(), prod.getPimage(),
				prod.getPimage_short(), prod.getPdate(), prod.getIs_hot(), prod.getPdesc(), prod.getPflag(), prod.getCid(),
				prod.getPid() };
		// 执行
		try {
			runner.update(sqlUpdate, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void add(Product prod) {
		// 商品：pid、商品名、市场价格、促销价格、图片地址、缩略图地址、上架时间、是否热门、描述、标记（是否下架）、商品分类ID（外键）
		// sql
		String sqlAdd = "insert into product values(?, ?, ?, ?, ?, ?, ?, ?, ?, ? ,?);";
		// 参数
		Object[] params = { prod.getPid(), prod.getPname(), prod.getMarket_price(), prod.getShop_price(), prod.getPimage(),
				prod.getPimage_short(), prod.getPdate(), prod.getIs_hot(), prod.getPdesc(), prod.getPflag(), prod.getCid() };
		// 执行
		try {
			runner.update(sqlAdd, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
