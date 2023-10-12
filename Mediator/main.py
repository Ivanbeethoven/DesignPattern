import random

# 中介者接口
class AirTrafficControl:
    def request_land(self, aircraft):
        pass

    def request_takeoff(self, aircraft):
        pass

# 具体中介者
class Tower(AirTrafficControl):
    def __init__(self):
        self.aircrafts = []
        self.runways = []  # 保存跑道的数组
        self.waiting_queue = []
        self.military_aircrafts = []  # 保存军事飞机的数组

    def request_land(self, aircraft):
        if isinstance(aircraft, Aircraft):
            available_runways = [runway for runway in self.runways if not runway.is_locked and not runway.is_occupied]
            if available_runways:
                selected_runway = random.choice(available_runways)
                selected_runway.is_occupied = True
                aircraft.current_runway = selected_runway  # 记录飞机的当前跑道
                self.aircrafts.append((aircraft, selected_runway))
                print(f"{aircraft.name} has been cleared to land on {selected_runway.name}.")
            else:
                print(f"No available runway for {aircraft.name}. It is in the holding pattern.")
                self.waiting_queue.append(aircraft)
        elif isinstance(aircraft, MilitaryAircraft):
            if all(runway.is_occupied for runway in self.runways):
                # 军事飞机要求占用所有跑道
                for runway in self.runways:
                    runway.is_occupied = True
                self.military_aircrafts.append(aircraft)
                print(f"Military aircraft {aircraft.name} has been cleared to land on all runways.")
            else:
                print(f"Military aircraft {aircraft.name} is in the holding pattern. All runways are not available.")
        else:
            print("Invalid request.")

    def request_takeoff(self, aircraft):
        if isinstance(aircraft, Aircraft):
            aircraft_info = next((info for info in self.aircrafts if info[0] == aircraft), None)
            if aircraft_info:
                _, runway = aircraft_info
                self.aircrafts.remove(aircraft_info)
                runway.is_occupied = False  # 标记跑道为非占用状态
                self.runways.append(runway)
                print(f"{aircraft.name} has taken off from {runway.name}.")
                if self.waiting_queue:
                    next_aircraft = self.waiting_queue.pop(0)
                    self.request_land(next_aircraft)
            else:
                print(f"Aircraft {aircraft.name} is not in the airspace or not assigned to any runway.")
        elif isinstance(aircraft, MilitaryAircraft):
            if all(runway.is_occupied for runway in self.runways):
                # 军事飞机要求占用所有跑道
                for runway in self.runways:
                    runway.is_occupied = False
                self.military_aircrafts.remove(aircraft)
                print(f"Military aircraft {aircraft.name} has taken off from all runways.")
            else:
                print(f"Military aircraft {aircraft.name} cannot take off. Not all runways are available.")
        else:
            print("Invalid request.")

# 飞机对象
class Aircraft:
    def __init__(self, name):
        self.name = name
        self.current_runway = None  # 记录飞机当前所在的跑道

    def request_land(self):
        tower.request_land(self)

    def request_takeoff(self):
        tower.request_takeoff(self)

# 跑道对象
class Runway:
    def __init__(self, name):
        self.name = name
        self.is_occupied = False  # 初始时，跑道未被占用
        self.is_locked = False  # 初始时，跑道未被锁定

    def lock(self):
        self.is_locked = True

    def unlock(self):
        self.is_locked = False

# 新的军事飞机类
class MilitaryAircraft:
    def __init__(self, name):
        self.name = name
        self.current_runway = None  # 记录飞机当前所在的跑道

    def request_land(self):
        tower.request_land(self)

    def request_takeoff(self):
        tower.request_takeoff(self)

def main():
    global tower
    tower = Tower()

    plane1 = Aircraft("Flight 123")
    plane2 = Aircraft("Flight 456")
    plane3 = Aircraft("Flight 789")
    plane4 = Aircraft("Flight 101")
    runway1 = Runway("Runway 1")
    runway2 = Runway("Runway 2")
    runway3 = Runway("Runway 3")
    military_plane = MilitaryAircraft("Stealth Bomber")

    tower.runways.extend([runway1, runway2, runway3])

    # Scenario 1: Planes request landing on available runways.
    plane1.request_land()
    plane2.request_land()
    plane3.request_land()

    # Scenario 2: Lock a runway and see how planes react.
    runway2.lock()  # Lock Runway 2
    plane4.request_land()  # Plane 4 attempts to land on locked runway, should not land.
    runway2.unlock()  # Unlock Runway 2
    plane4.request_land()  # Plane 4 lands on unlocked runway2.

    # Scenario 3: Planes queue up when runways are occupied.
    plane1.request_land()
    plane2.request_land()
    plane3.request_land()
    plane4.request_land()  # Plane 4 enters holding pattern, runway1 is occupied.
    plane5 = Aircraft("Flight 777")
    plane5.request_land()  # Plane 5 enters holding pattern, runway1 is still occupied.
    runway1.unlock()  # Plane 1 takes off, runway1 is now available.
    plane4.request_land()  # Plane 4 lands on now available runway1.
    runway3.lock()  # Lock Runway 3
    plane5.request_land()  # Plane 5 lands on locked runway3, should not land.
    runway3.unlock()  # Unlock Runway 3
    plane5.request_land()  # Plane 5 lands on unlocked runway3.

    # Scenario 4: Planes request takeoff.
    plane1.request_takeoff()
    plane2.request_takeoff()
    plane3.request_takeoff()

    # Scenario 5: Military Aircraft lands and takes off.
    military_plane.request_land()
    military_plane.request_takeoff()

if __name__ == "__main__":
    main()
