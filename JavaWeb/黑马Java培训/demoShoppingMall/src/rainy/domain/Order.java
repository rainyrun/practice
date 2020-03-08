package rainy.domain;

import java.util.Arrays;
import java.util.Date;
import java.util.List;

public class Order {
	private String oid;// 订单编号
	private Date ordertime;// 订单生成时间
	private double total;// 订单总金额
	private int state;// 订单状态
	private String address;// 收货地址
	private String name;// 收货人
	private String phone;// 电话
	
	private Customer customer;// 下单用户
	private List<OrderItem> items;// 订单项

	// 计算订单总金额
	public void setTotal(){
		total = 0;
		// 遍历订单项，将订单项的金额相加
		if(items != null) {
			for (OrderItem orderItem : items) {
				total += orderItem.getTotal();
			}
		}
	}

	// setter&getter
	public String getOid() {
		return oid;
	}

	public void setOid(String oid) {
		this.oid = oid;
	}

	public Date getOrdertime() {
		return ordertime;
	}

	public void setOrdertime(Date ordertime) {
		this.ordertime = ordertime;
	}

	public double getTotal() {
		return total;
	}

	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public Customer getCustomer() {
		return customer;
	}

	public void setCustomer(Customer customer) {
		this.customer = customer;
	}

	public List<OrderItem> getItems() {
		return items;
	}

	public void setItems(List<OrderItem> items) {
		this.items = items;
		setTotal();
	}
	// 注1
	public void setTotal(double total) {
		this.total = total;
	}

	@Override
	public String toString() {
		return "Order [oid=" + oid + ", ordertime=" + ordertime + ", total=" + total + ", state=" + state + ", address="
				+ address + ", name=" + name + ", phone=" + phone + ", customer=" + customer + "]";
	}
	
}
/*
 * 注1: 本来以为total需要计算得出，不需要默认的setter方法。结果发现从数据库加载数据到对象的时候，仍需要setter方法。
 */
