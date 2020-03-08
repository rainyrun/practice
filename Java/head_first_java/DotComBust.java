/**“打网站(DotComBust)”游戏设计
1. 有一个7*7棋盘，棋盘上有3个网站(DotCom)。
2. 每三个连在一起成一行或一列的格子，为一个网站(DotCom)。当网站(DotCom)中的3个格子都被击中后，网站被击落，并在屏幕上输出sunk。当三个网站都被击落后，游戏结束。
3. 在控制台输入坐标，检查输入的坐标是否命中网站，有3种结果：Hit，Miss，Sunk。重复直到游戏结束
*/

import java.util.*;

public class DotComBust{
	private GameHelper helper = new GameHelper();
	//网站列表
	private ArrayList<DotCom> dotComList = new ArrayList<>();
	//猜中的次数
	private int numOfGuess = 0;

	/**初始化游戏，包括：生成3个网站，放置3个网站。
	*/
	public void setUpGame(){
		DotCom one = new DotCom();
		one.setName("baidu.com");

		DotCom two = new DotCom();
		two.setName("alibaba.com");

		DotCom three = new DotCom();
		three.setName("tecent.com");

		dotComList.add(one);
		dotComList.add(two);
		dotComList.add(three);

		for(DotCom dotComToSet : dotComList){
			dotComToSet.getLocations(helper.placeDotCom(3));
		}
	}

	/**开始游戏
	1. 用户输入位置
	2. 输出打击结果
	3. 3个网站被击落，游戏结束
	*/
	private void playGame(){		
		while(!dotComList.isEmpty()){
			//用户输入
			String location = helper.getUserString();
			checkUserGuess(locaton);
		}
		finishGame();
	}

	/**根据玩家输入的位置，处理网站
	输入：玩家猜的位置
	*/
	private void checkUserGuess(String userGuess){
		numOfGuess++;
		String result = "miss";
		for(DotCom dotComToTest: dotComList){
			result = dotComToTest.checkYourself(userGuess);
			if(result.equals("sunk")){
				dotComList.remove(dotComToTest);
				break;
			}
			else if(result.equals("hit"))
				break;
		}
		System.out.println(result);
	}

	/**结束游戏，输出用户猜的次数
	*/
	private void finishGame(){
		System.out.println("totle : " + numOfGuess);
	}

	public static void main(String[] args){
		DotComBust game = new DotComBust;
		game.setUpGame();
		game.playGame();
	}
}

class DotCom{
	//位置数组
	private ArraysList<String> locations = new ArraysList<>();
	private String dotName;
	//根据传入的数组设置位置
	public void setLocation(ArraysList<String> dotLocation){
		locations = dotLocation;
	}
	/**检查自己是否被击中或击沉
	输入：玩家猜的位置
	输出：miss, hit, sunk
	*/
	public String checkYourself(String userGuess){
		String result = "miss";
		for(String position : locations){
			if(position.equals(userGuess)){
				locations.remove(position);
				if(locations.isEmpty())
					result = "sunk";
				else
					result = "hit";
				break;
			}
		}
		return result;
	}
	/**设置自己的名字
	输入：名字
	*/
	public void setName(String name){
		dotName = name;
	}

}

